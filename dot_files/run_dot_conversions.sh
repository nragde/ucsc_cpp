#!/bin/bash
for filename in $(pwd)/*.dot; do
	/usr/local/bin/dot -Tpdf "$filename" -o "$(pwd)/$(basename "$filename" .dot).pdf"
done