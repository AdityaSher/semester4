
for i in *
do
	`mv "$1" "$(echo $i|tr '[:lower:][:upper:]' '[:upper:][:lower:]')"`

done
