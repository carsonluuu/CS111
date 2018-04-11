#NAME: Jiahui Lu
#EMAIL: carsonluuu@gmail.com
#UID: 204945099

default:
		gcc -g -Wall -Wextra lab0.c -o lab0
check:
		

		@echo "Bacon ipsum dolor amet t-bone swine chuck rump pork belly chicken corned beef. Picanha hamburger salami turducken tail. Capicola pork chop short loin, frankfurter brisket meatloaf cupim beef leberkas ground round drumstick pig. Turducken capicola turkey, kevin porchetta meatball sirloin flank drumstick jowl ground round filet mignon andouille. Andouille chuck hamburger, salami kevin jowl beef short loin alcatra. T-bone pork loin rump shoulder leberkas ribeye pork chop filet mignon doner alcatra." > input.txt
		@./lab0 < input.txt > output.txt ; \
		if [ $$? -ne 0 ] ; \
		then \
				echo "Return value of Exit Code is not right! It is: $$? here" ; \
				exit 1 ; \
		fi
		@diff -q input.txt output.txt
		@rm -f output.txt

		@./lab0 --input=input.txt > output.txt ; \
		if [ $$? -ne 0 ] ; \
		then \
				echo "Return value of Exit Code is not right! It is: $$? here" ; \
				exit 1 ; \
		fi
		@diff -q input.txt output.txt
		@rm -f output.txt

		@./lab0 --output=output.txt < input.txt ; \
		if [ $$? -ne 0 ] ; \
		then \
				echo "Return value of Exit Code is not right! It is: $$? here" ; \
				exit 1 ; \
		fi
		@diff -q input.txt output.txt
		@rm -f output.txt

		@./lab0 --input=input.txt --output=output.txt ; \
		if [ $$? -ne 0 ] ; \
		then \
				echo "Return value of Exit Code is not right! It is: $$? here" ; \
				exit 1 ; \
		fi
		@diff -q input.txt output.txt
		@rm -f output.txt

		@exec 2> /dev/null; \
		./lab0 --Jiahui; \
		if [ $$? -ne 1 ] ; \
		then \
			echo "Return value of Exit Code is not right! It is: $$? here" ; \
		fi

		@exec 2> /dev/null; \
		./lab0 --catch --segfault; \
		if [ $$? -ne 4 ] ; \
		then \
			echo "Return value of Exit Code is not right! It is: $$? here" ; \
		fi

		@./lab0 --input=null.txt > output.txt 2> /dev/null ; \
		if [ $$? -ne 2 ] ; \
		then \
			echo "Return value of Exit Code is not right! It is: $$? here" ; \
			exit 1 ; \
		fi
		@rm -f output.txt

		@echo "Test Checking for Exit Code 3 for output.txt Writing" > output.txt
		@chmod -w output.txt
		@./lab0 --output=output.txt < input.txt 2> /dev/null ; \
		if [ $$? -ne 3 ] ; \
		then \
			echo "Return value of Exit Code is not right! It is: $$? here" ; \
			exit 1 ; \
		fi
		@rm -f output.txt

		@echo "Passed All Personal Tests"

clean:
		@rm -f lab0
		@rm -f input.txt
		@rm -f output.txt
		@rm -f lab0-204945099.tar.gz

dist:
		@tar -czf lab0-204945099.tar.gz Makefile lab0.c backtrace.png breakpoint.png README
