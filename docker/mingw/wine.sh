#!/bin/sh -xe

echo
echo '--> Set Qt and Tools PATH for wine'
echo

# TODO: Not working
cat - <<EOF > /tmp/path.reg
Windows Registry Editor Version 5.00
[HKEY_CURRENT_USER\\Environment]
"Path"="$(find "/root/.wine/drive_c/Qt" -type d -name bin -o -name Ninja | sed "s|/root/.wine/drive_c|C:|" | sed 's|/|\\\\|g' | tr '\n' ';')"
EOF

wine regedit /tmp/path.reg

echo
echo '--> Create helper functions'
echo

cat - <<\EOF | tee /usr/local/bin/cmake
#!/bin/sh
wine cmake "$@"
EOF

cat - <<\EOF | tee /usr/local/bin/ninja
#!/bin/sh
wine ninja "$@"
EOF

cat - <<\EOF | tee /usr/local/bin/cpack
#!/bin/sh
wine cpack "$@"
EOF

chmod +x /usr/local/bin/*
