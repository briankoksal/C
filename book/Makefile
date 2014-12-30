
MAIN = main.pdf
main: $(MAIN)

all: $(MAIN)

%.pdf: %.tex
	latexmk -f -pdf -pdflatex="pdflatex -interactive=nonstopmode -shell-escape" -use-make $<

.PHONY: show clean deepclean

clean:
	latexmk -CA
deepclean: clean cleanbib cleancode
	rm -f *.log *.aux *.dvi *.bbl *.blg *.ilg *.toc *.lof *.lot *.idx *.ind *.ps *.gnuplot *~ *gnuplotlatex* *gnuplottex*
show:
	open $(MAIN)
auto: clean main show

