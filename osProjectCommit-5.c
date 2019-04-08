// process code
void* processCode(void *arg) {
        int p = *((int *) arg);
        int lockResources,*safeSeq,nProcessRan,condition;
        int i,nResources,**allocated,**need,*resources;

	// lock resources
        pthread_mutex_lock(&lockResources);

        // condition check
        while(p != safeSeq[nProcessRan])
                pthread_cond_wait(&condition, &lockResources);

	// process
        printf("\n--> Process %d", p+1);
        printf("\n\tAllocated : ");
        for(i=0; i<nResources; i++)
                printf("%3d", allocated[p][i]);

        printf("\n\tNeeded    : ");
        for(i=0; i<nResources; i++)
                printf("%3d", need[p][i]);

        printf("\n\tAvailable : ");
        for(i=0; i<nResources; i++)
                printf("%3d", resources[i]);

        printf("\n"); sleep(1);

        printf("\tResource Allocated!");
        printf("\n"); sleep(1);
        printf("\tProcess Code Running...");
        printf("\n"); sleep(rand()%3 + 2); // process code
        printf("\tProcess Code Completed...");
        printf("\n"); sleep(1);
        printf("\tProcess Releasing Resource...");
        printf("\n"); sleep(1);
        printf("\tResource Released!");

	for(i=0; i<nResources; i++)
                resources[i] += allocated[p][i];

        printf("\n\tNow Available : ");
        for(i=0; i<nResources; i++)
                printf("%3d", resources[i]);
        printf("\n\n");

        sleep(1);

	// condition broadcast
        nProcessRan++;
        pthread_cond_broadcast(&condition);
        pthread_mutex_unlock(&lockResources);
	pthread_exit(NULL);
}
