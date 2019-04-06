  // allocated
        printf("\n");
        for(i=0; i<nProcesses; i++) {
                printf("\nResource allocated to process %d (R1 R2 ...)? ", i+1);
                for(j=0; j<nResources; j++)
                        scanf("%d", &allocated[i][j]);
        }
        printf("\n");

	// maximum required resources
        for(i=0; i<nProcesses; i++) {
                printf("\nMaximum resource required by process %d (R1 R2 ...)? ", i+1);
                for(j=0; j<nResources; j++)
                        scanf("%d", &maxRequired[i][j]);
        }
        printf("\n");

	// calculate need matrix
        need = (int **)malloc(nProcesses * sizeof(*need));
        for(i=0; i<nProcesses; i++)
                need[i] = (int *)malloc(nResources * sizeof(**need));

        for(i=0; i<nProcesses; i++)
                for(j=0; j<nResources; j++)
                        need[i][j] = maxRequired[i][j] - allocated[i][j];
