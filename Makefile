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

run:
	$(G4INSTALL)/bin/$(G4SYSTEM)/test30

clean:
	rm *.root *.profile

runFission:
	$(G4INSTALL)/bin/$(G4SYSTEM)/test30 runs/uFission.mac

debug:
	@echo '::: entering gdb. (gdb) help/run/quit'
	gdb $(G4INSTALL)/bin/$(G4SYSTEM)/test30

profile:
	@echo '::: profiling'
	gprof $(G4INSTALL)/bin/$(G4SYSTEM)/test30 > test30.profile
	gprof -b $(G4INSTALL)/bin/$(G4SYSTEM)/test30 | more