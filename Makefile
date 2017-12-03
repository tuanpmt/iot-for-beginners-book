.PHONY: pdf
LANG ?= vi
pdf:
	bundle exec asciidoctor-pdf -a lang=$(LANG) -r asciidoctor-diagram -a pdf-stylesdir=theme/pdf -a pdf-style=basic -a pdf-fontsdir=theme/fonts -r asciidoctor-diagram -o iot-for-beginners.$(LANG).pdf iot-for-beginners.adoc 2>/dev/null

html:
	bundle exec asciidoctor -a lang=$(LANG) -r asciidoctor-diagram iot-for-beginners.$(LANG).html iot-for-beginners.adoc

epub:
	bundle exec asciidoctor-epub3 -a lang=$(LANG) -r asciidoctor-diagram iot-for-beginners.$(LANG).epub iot-for-beginners.adoc
