.PHONY: pdf

pdf:
	bundle exec asciidoctor-pdf -r asciidoctor-diagram -a pdf-stylesdir=theme/pdf -a pdf-style=basic -a pdf-fontsdir=theme/fonts -r asciidoctor-diagram index.adoc 2>/dev/null

epub:
	bundle exec asciidoctor-epub3 -r asciidoctor-diagram index.adoc
