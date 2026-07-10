from dataclasses import dataclass
from pathlib import Path
import sys

from datasets import load_dataset

rootdir = Path("codexglue")
rootdir.mkdir(parents=True, exist_ok=True)

@dataclass(frozen=True)
class CodeDict:
    id: int
    code: str
    label: str

ds = load_dataset("google/code_x_glue_cc_clone_detection_poj104")

labels_set = [ "train", "validation", "test" ]

codes = set()

for label in labels_set:
    for test in ds[label]:
        codes.add(CodeDict(
            test["id"], test["code"], test["label"]
        ))

assert len(codes) == sum([ len(ds[label]) for label in labels_set ]), \
    "duplicate code files"

labels = set()

for code in codes:
    labels.add(code.label)

codes_sorted = sorted(
    codes,
    key = lambda x: (x.id, x.code, x.label)
)

for index, item in enumerate(codes_sorted):
    workdir = rootdir / Path(item.label)
    workdir.mkdir(parents=True, exist_ok=True)
    code = item.code.replace("\r\n", "\n").replace("\r", "\n")

    with open(workdir / f"{str(index)}.cpp", "w", encoding="utf-8", newline="\n") as f:
        f.write(code)

count = 0
for label in labels:
    workdir = Path(label)
    count += sum(1 for item in workdir.iterdir() if item.is_file())

assert len(codes) == count, \
    "duplicate code files"

sys.exit(0)
