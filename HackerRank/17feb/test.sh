cat > testInput___;
python3 stringsbrute.py < testInput___ > bruteOutput___
./strings < testInput___ > fancyOutput___
diff bruteOutput___ fancyOutput___
