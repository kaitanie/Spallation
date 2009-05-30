#----------------------------------------------------------
# Using Github.com code management

# Usage example 'make -f Makefile addPK'
# Init:
# A. fork git://github.com/kaitanie/Spallation.git in Github to you own account
# B. only  once
#       git clone git://github.com/[username]/Spallation.git

# When you start your session do 'make addPK' and 'make getPK' 

# [local edit]
# git diff
# git status
# git commit -a -m '[your comment]'  (add all changes)
# git push git@github.com:[username]/Spallation.git

#git revert HEAD  (in case of bad commit this reverses it)



pushAH:
	git push git@github.com:aatos/Spallation.git

addPK:
	git remote add pekka git://github.com/kaitanie/Spallation.git

getPK:
	git fetch pekka
	git merge pekka/master


