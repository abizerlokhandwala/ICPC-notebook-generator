# ICPC-Notebook
ICPC notebook generator, with font size 11 and code-color schema.  
Notebook for Indian teams at ACM ICPC. Sources are mainly from the Stanford University ACM team.
Fixed the tex error (missing 'tocloft.ins').

# Usage
C++ and Python notebook files are located in the cpp/ and python/ directories, respectively.
To add files and sections to a notebook, add it to a subfolder and add it to the corresponding `contents.txt` file.

`contents.txt` has the following format :
```
[Section name]
subfolder/file.cpp  Description of the file      # Optional end-of-line comment
```
Note that there is a tab between the filename and its description. You shouldn't use tabs anywhere else in this file.

The generator script can add text highlighting for the following file formats : `.h, .c, .cc, .cpp, .java, .py`

Once the `contents.txt` file is ready, the notebook can be generated using `python generator.py [python|cpp]` (Eg: `python generator.py cpp`, if you want to generate using the cpp folder codes)
