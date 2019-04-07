// get safe sequence
	safeSeq = (int *)malloc(nProcesses * sizeof(*safeSeq));
        for(i=0; i<nProcesses; i++) safeSeq[i] = -1;

        if(!getSafeSeq()) {
                printf("\nUnsafe State! The processes leads the system to a unsafe state.\n\n");
                exit(-1);
        }

        printf("\n\nSafe Sequence Found : ");
        for(i=0; i<nProcesses; i++) {
                printf("%-3d", safeSeq[i]+1);
        }

        printf("\nExecuting Processes...\n\n");
        sleep(1);
	
	// run threads
	pthread_t processes[nProcesses];
        pthread_attr_t attr;
        pthread_attr_init(&attr);

	int processNumber[nProcesses];
	for(i=0; i<nProcesses; i++) processNumber[i] = i;

        for(i=0; i<nProcesses; i++)
                pthread_create(&processes[i], &attr, processCode, (void *)(&processNumber[i]));

        for(i=0; i<nProcesses; i++)
                pthread_join(processes[i], NULL);

        printf("\nAll Processes Finished\n");	
	
	// free resources
        free(resources);
        for(i=0; i<nProcesses; i++) {
                free(allocated[i]);
                free(maxRequired[i]);
		free(need[i]);
        }
        free(allocated);
        free(maxRequired);
	free(need);
        free(safeSeq);
}
