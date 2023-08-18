patch = "/Users/susie/Documents/projects/miniapp/ChromiumTaintTracking/v8_patch"
with open(patch) as f:
	content = f.read()

lines = content.split("\n")
lines = [i for i in lines if i.startswith("diff --git")]
file_set = set(lines)
print(len(lines))
print(len(file_set))
# print(file_set)

with open("v8_changed_files.txt", "w") as f:
	tmp = list(file_set)
	tmp.sort()
	for i in tmp:
		f.write(i+'\n')