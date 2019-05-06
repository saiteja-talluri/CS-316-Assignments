#!/bin/bash

testdir="tests"

if [ ! -d "$testdir" ]; 
then
	echo "No directory named $testdir"
	exit
fi

make

for filename in "$testdir"/*.c; do

	if [ "$#" -eq 1 ]; then
		./mysclp "$filename" 2>"$filename.myerr"
		mv "$filename.spim" "$filename.myspim"
		./sclp "$filename" 2>"$filename.err"
		DIFF1=$(diff "$filename.spim" "$filename.myspim")
		DIFF2=$(diff "$filename.err" "$filename.myerr")
		DIFF3=""
	else
		./mysclp -icode "$filename" 2>"$filename.myerr"
		mv "$filename.spim" "$filename.myspim"
		mv "$filename.ic" "$filename.myic"
		./sclp -icode "$filename" 2>"$filename.err"
		DIFF1=$(diff "$filename.spim" "$filename.myspim")
		DIFF2=$(diff "$filename.err" "$filename.myerr")
		DIFF3=$(diff "$filename.ic" "$filename.myic")
	fi


	./mysclp -tokens -ast -symtab -eval "$filename" 2> /dev/null
	mv "$filename.eval" "$filename.myeval"
	mv "$filename.ast" "$filename.myast"
	mv "$filename.sym" "$filename.mysym"
	mv "$filename.toks" "$filename.mytoks"

	./sclp -tokens -ast -symtab -eval "$filename" 2> /dev/null
	DIFF4=$(diff "$filename.ast" "$filename.myast")
	DIFF5=$(diff "$filename.eval" "$filename.myeval")
	DIFF6=$(diff "$filename.toks" "$filename.mytoks")
	if grep -q "sclp error:" "$filename.err"; then
	  DIFF6=""
	  if grep -q "cs316: Error" "$filename.myerr"; then
	  	DIFF2=""
	  fi
	fi
	
	DIFF7=$(diff "$filename.sym" "$filename.mysym")
	
	echo "------------------------------------------------------------------------------------------------------------------------------------------------------"
	echo "filename = $filename"
	echo "------------------------------------------------------------------------------------------------------------------------------------------------------"

	if [ "$DIFF1" != "" ]
	then
		echo "spim code comparison failed on $filename. Continuing further tests."
		echo "Showing diff:"
		echo "$DIFF1"
		echo "------------------------------------------------------------------------------------------------------------------------------------------------------"
	fi

	if [ "$DIFF2" != "" ]
	then
		echo "Error message comparison failed on $filename. "
		echo "Showing diff:"
		echo "$DIFF2"
		echo "Continuing with further tests."
		echo "------------------------------------------------------------------------------------------------------------------------------------------------------"
	fi	

	if [ "$DIFF3" != "" ]
	then
		echo "icode comparison failed on $filename. Continuing further tests."
		echo "Showing diff:"
		echo "$DIFF3"
		echo "------------------------------------------------------------------------------------------------------------------------------------------------------"
	fi


	if [ "$DIFF4" != "" ]
	then
		echo "ast comparison failed on $filename. Continuing further tests."
		echo "Showing diff:"
		echo "$DIFF4"
		echo "------------------------------------------------------------------------------------------------------------------------------------------------------"
	fi

	if [ "$DIFF5" != "" ]
	then
		echo "eval comparison failed on $filename. Did not run further tests (lexicographic ordering)."
		echo "Showing diff:"
		echo "$DIFF5"
		echo "------------------------------------------------------------------------------------------------------------------------------------------------------"
	fi

	if [ "$DIFF6" != "" ]
	then
		if ! [ -s "$filename.myerr" ]
		then
			echo "tokens comparison failed on $filename even though myerr is empty. Did not run further tests (lexicographic ordering)."
			exit
		fi
		echo "tokens comparison failed on $filename, but myerr is non-empty. Continuing tests"
		echo "Showing diff:"
		echo "$DIFF6"
		echo "------------------------------------------------------------------------------------------------------------------------------------------------------"
	fi

	if [ "$DIFF7" != "" ]
	then
		echo "symtab comparison failed on $filename. Did not run further tests (lexicographic ordering)."
		echo "Showing diff:"
		echo "$DIFF7"
		echo "------------------------------------------------------------------------------------------------------------------------------------------------------"
	fi

	[ "$DIFF1" == "" ] && [ "$DIFF2" == "" ] && [ "$DIFF3" == "" ] && [ "$DIFF4" == "" ] && [ "$DIFF4" == "" ] && [ "$DIFF5" == "" ] && [ "$DIFF6" == "" ] && [ "$DIFF7" == "" ] && echo "Passed on $filename"
	!([ "$DIFF1" == "" ] && [ "$DIFF2" == "" ] && [ "$DIFF3" == "" ] && [ "$DIFF4" == "" ] && [ "$DIFF4" == "" ] && [ "$DIFF5" == "" ] && [ "$DIFF6" == "" ] && [ "$DIFF7" == "" ]) && echo "Failed on $filename"
	echo "------------------------------------------------------------------------------------------------------------------------------------------------------"
	# exit
done

# echo "All testcases passed!"



