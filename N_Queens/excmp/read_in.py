data = {"C":[] ,"C++":[] ,"Python":[] ,"Java":[] ,"Rust":[]}
with open("New Text Document.txt" ,"r") as _file:
	_k = ""
	for line in _file:
		if line.strip() == "C" or line.strip() =="C++" or line.strip() =="Python" or line.strip() =="Java" or line.strip() =="Rust":
			_k = line.strip()
			continue
		if "\\" in line or not len(line.strip()) or "N" in line or "m" in line : continue
		# print(line)
		data[_k].append(float(line.strip().strip(",")))

print(data)

import json
with open("benchmarks_data.json" ,"w") as jsnfile:
	json.dump(data ,jsnfile)
