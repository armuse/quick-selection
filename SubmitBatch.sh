#!/bin/sh

pwd
sample=$2
region=$3
#RESULTS=/export/scratch2/amontalb/tree_try/lock

tar -xzvf JOB.tar
ls 
pwd
export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
alias setupATLAS='source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh'
setupATLAS
rcSetup Base,2.4.22

echo "Set everything up"
./NtupleReader ${sample} ${region}

#lockfile $HOME/Alyssa.lock

cp */*.root /export/scratch2/amontalb/out-MJ-El2/
cp *.cpp /export/scratch2/amontalb/out-MJ-El2/
cp Ntupl* /export/scratch2/amontalb/out-MJ-El2/
#rm -f $HOME/Alyssa.lock

