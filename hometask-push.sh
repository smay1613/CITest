<!/bin/bash
git status
git add .
git status
if [[ -z $(git remote -v) ]]; then
  echo "Please add remote repository first. Command: git remote add origin *LINK*"
fi
git commit -m "Implements hometask"
git status
git push
