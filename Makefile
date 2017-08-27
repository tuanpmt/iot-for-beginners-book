.PHONY: pdf

pdf:
	bundle exec asciidoctor-pdf -r asciidoctor-diagram -a pdf-stylesdir=pdf -a pdf-style=basic -a pdf-fontsdir=fonts -r asciidoctor-diagram index.adoc 2>/dev/null
