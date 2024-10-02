cloneurl=`git remote -v | cut -d ' ' -f 1 | cut -d $'\t' -f 2 | head -n 1`
cd ..
git clone $cloneurl testRepo
cd testRepo
make compile
make run

cd ..
rm -r testRepo