#!/bin/bash

btag=("2tag")
#btag=("0tag" "1tag" "2tag")
#jtag=("2jet")
jtag=("2jet" "3jet")
Sample=("data16" "Wjets" "ttbar" "Zjets" "singletop" "signal")
ptW=("150ptV")
#ptW=("0_150ptV")
#ptW=("0_150ptV" "150ptV" )
MJSample=("MJ_data" "MJ_ttbar" "MJ_Wjets" "MJ_singletop" "MJ_Zjets")

#if condor is acting up, use lockfile + sleep

for i in "${btag[@]}"; do
  for j in "${jtag[@]}"; do
    for k in "${ptW[@]}"; do
      for m in "${MJSample[@]}"; do
#      condor_submit condor_submit.job sample=$m region=$i$j$k
#      sleep 5
#      for m in "${Sample[@]}"; do
#      condor_submit condor_submit.job sample=$m region=$i$j$k
#        sleep 5
      echo $m $i$j$k
     ./NtupleReader $m $i$j$k
      done
    done
  done
done
