import sys
if __name__ == '__main__':
	input_file  = sys.argv[1] + ".h"
	output_file = sys.argv[1] + ".c"
	#content = "#include \"" + input_file[input_file.rfind("/")+1:] + "\"\n\n" 
	content = ""
	for line in open(input_file ,'r'):
		if line.find(");") != -1:
			if open(output_file , 'r').read().find(line[:-2]) == -1:
				content += line[:-2] + "\n{\n\n}\n"

	open(output_file , 'a').write(content)


