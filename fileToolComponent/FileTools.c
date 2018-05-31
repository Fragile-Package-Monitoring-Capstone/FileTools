#include "legato.h"
#include "interfaces.h"
#include <unistd.h>

le_result_t *createFile(char *FilePath, int userID) {
    FILE *f = fopen(FilePath, "a");
    if(!f) {
        LE_ERROR("Failed to create file %s, error %d", FilePath, errno);
        return (void *)LE_FAULT;
    }
    if(chown(FilePath, userID, -1) != 0) {
        LE_ERROR("Failed to change ownership on file %s, error %d", FilePath, errno);
        return (void *)LE_FAULT;
    }
    
    return LE_OK;
} 
COMPONENT_INIT {}
