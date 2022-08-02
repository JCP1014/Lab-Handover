# Lane-Merging
## C++
### Compilation
```
make
```

### Execution
```
./main p N W= W+ inputFile
```
* p: trffic density (the average number of incoming vehicles on each lane per second)
* N: the number of vehicles from each lane
* W=: the minimum time gap between two consecutive vehicles if they are from the same lane ( $W^=$ in the thesis)
* W+: the minimum time gap between two consecutive vehicles if they are from different lanes ( $W^+$ in the thesis)
* inputFile: the path of the input file
  * this argument is optional
  * if this argument is empty, then randomly generate traffics based on `p` and `N`


## SUMO
### Compilation
```
make
```

### Execution
```
./sumo_runner p N W= W+ isNewTest inputFile
```
* p: trffic density (the average number of incoming vehicles on each lane per second)
* N: the number of vehicles from each lane
* W=: the minimum time gap between two consecutive vehicles if they are from the same lane ( $W^=$ in the thesis)
* W+: the minimum time gap between two consecutive vehicles if they are from different lanes ( $W^+$ in the thesis)
* isNewTest: enter 'T' or 'F'
  * T: generate a new test case
  * F: use the existing input file
* inputFile: the path of the input file
  * this argument is optional
  * if this argument is empty and `isNewTest` is 'T', then randomly generate traffics based on `p` and `N` and write to `sumo_data/laneMerging.rou.xml`
  * if this argument is empty and `isNewTest` is 'F', then use the existing `sumo_data/laneMerging.rou.xml` as the input file


## Other Notes
* [About SUMO](https://hackmd.io/rrEQsktVSK6cwu3DQc_cZQ)
* [Usage of functions](https://hackmd.io/_pqioOhPShOvJ8Va8xNbWQ)
