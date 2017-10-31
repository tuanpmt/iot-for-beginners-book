.PHONY: pdf
MASK ?= iotmaker-wm.png
pdf:
	bundle exec asciidoctor-pdf -a mask=$(MASK) -r asciidoctor-diagram -a pdf-stylesdir=theme/pdf -a pdf-style=basic -a pdf-fontsdir=theme/fonts -r asciidoctor-diagram index.adoc 2>/dev/null

html:
	bundle exec asciidoctor -r asciidoctor-diagram index.adoc

epub:
	bundle exec asciidoctor-epub3 -r asciidoctor-diagram index.adoc
