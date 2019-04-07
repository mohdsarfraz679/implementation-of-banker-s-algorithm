bool getSafeSeq() {
	// get safe sequence
		int nResources,i,j,k,*resources;
		int nProcesses,**need,**allocated,**safeSeq;
        int tempRes[nResources];
        for(i=0; i<nResources; i++) tempRes[i] = resources[i];

        bool finished[nProcesses];
        for(i=0; i<nProcesses; i++) finished[i] = false;
        int nfinished=0;
        while(nfinished < nProcesses) {
                bool safe = false;

                for(i=0; i<nProcesses; i++) {
                        if(!finished[i]) {
                                bool possible = true;

                                for(j=0; j<nResources; j++)
                                        if(need[i][j] > tempRes[j]) {
                                                possible = false;
                                                break;
                                        }

                                if(possible) {
                                        for(j=0; j<nResources; j++)
                                                tempRes[j] += allocated[i][j];
                                        safeSeq[nfinished] = i;
                                        finished[i] = true;
                                        ++nfinished;
                                        safe = true;
                                }
                        }
                }

                if(!safe) {
                        for(k=0; k<nProcesses; k++) safeSeq[k] = -1;
                        return false; // no safe sequence found
                }
        }
        return true; // safe sequence found
}
