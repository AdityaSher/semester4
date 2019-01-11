
#!/bin/bash

#$1 is line number $2 is file name
# -i is used to edit files in place (overwrite)
#d stands for delete

`sed -i ''$1''d'' $2` 



