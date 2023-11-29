JUST_CAT=$(cat ascii_characters.txt)
S21_CAT=$(./s21_cat ascii_characters.txt)

if [ "$JUST_CAT" = "$S21_CAT" ]; then
    echo "without flags: OK";
else
    echo "without flags: FAIL";
fi

JUST_CAT_B=$(cat -b ascii_characters.txt)
S21_CAT_B=$(./s21_cat -b ascii_characters.txt)

if [ "$JUST_CAT_B" = "$S21_CAT_B" ]; then
    echo "flags -b: OK";
else
    echo "flags -b: FAIL";
fi

JUST_CAT_E=$(cat -e ascii_characters.txt)
S21_CAT_E=$(./s21_cat -e ascii_characters.txt)

if [ "$JUST_CAT_E" = "$S21_CAT_E" ]; then
    echo "flags -e: OK";
else
    echo "flags -e: FAIL";
fi

JUST_CAT_N=$(cat -n ascii_characters.txt)
S21_CAT_N=$(./s21_cat -n ascii_characters.txt)

if [ "$JUST_CAT_N" = "$S21_CAT_N" ]; then
    echo "flags -n: OK";
else
    echo "flags -n: FAIL";
fi

JUST_CAT_S=$(cat -s ascii_characters.txt)
S21_CAT_S=$(./s21_cat -s ascii_characters.txt)

if [ "$JUST_CAT_S" = "$S21_CAT_S" ]; then
    echo "flags -s: OK";
else
    echo "flags -s: FAIL";
fi

JUST_CAT_T=$(cat -t ascii_characters.txt)
S21_CAT_T=$(./s21_cat -t ascii_characters.txt)

if [ "$JUST_CAT_T" = "$S21_CAT_T" ]; then
    echo "flags -t: OK";
else
    echo "flags -t: FAIL";
fi

JUST_CAT_T=$(cat -T ascii_characters.txt)
S21_CAT_T=$(./s21_cat -T ascii_characters.txt)

if [ "$JUST_CAT_T" = "$S21_CAT_T" ]; then
    echo "flags -T: OK";
else
    echo "flags -T: FAIL";
fi

JUST_CAT_E=$(cat -E ascii_characters.txt)
S21_CAT_E=$(./s21_cat -E ascii_characters.txt)

if [ "$JUST_CAT_E" = "$S21_CAT_E" ]; then
    echo "flags -E: OK";
else
    echo "flags -E: FAIL";
fi

JUST_CAT_B_GNU=$(cat --number-nonblank ascii_characters.txt)
S21_CAT_B_GNU=$(./s21_cat --number-nonblank ascii_characters.txt)

if [ "$JUST_CAT_B_GNU" = "$S21_CAT_B_GNU" ]; then
    echo "flags --number-nonblank: OK";
else
    echo "flags --number-nonblank: FAIL";
fi

JUST_CAT_N_GNU=$(cat --number ascii_characters.txt)
S21_CAT_N_GNU=$(./s21_cat --number ascii_characters.txt)

if [ "$JUST_CAT_N_GNU" = "$S21_CAT_N_GNU" ]; then
    echo "flags --number: OK";
else
    echo "flags --number: FAIL";
fi

JUST_CAT_S_GNU=$(cat --squeeze-blank ascii_characters.txt)
S21_CAT_S_GNU=$(./s21_cat --squeeze-blank ascii_characters.txt)

if [ "$JUST_CAT_S_GNU" = "$S21_CAT_S_GNU" ]; then
    echo "flags --squeeze-blank: OK";
else
    echo "flags --squeeze-blank: FAIL";
fi