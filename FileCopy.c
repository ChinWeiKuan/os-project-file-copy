/*
 * Project: File Copy Implementation
 * Authors: Kuan, Chin-Wei (官京緯)
 * Date: March 29, 2026
 * Description:
 * This program implements a simple file copy utility in C. It prompts the user for a source file and a destination file, then copies the contents of the source file to the destination file. The
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    char source_file[256];
    char dest_file[256];

    // Part 1: Prompt and read inputs
    // For the source file
    printf("Enter the source file name: ");
    scanf("%255s", source_file);

    // For the destination file
    printf("Enter the destination file name: ");
    scanf("%255s", dest_file);
    
    // Error handling for opening the source file
    int source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        perror("Unable to open source file");
        exit(1);
    }

    // Error handling for opening/creating the destination file
    int dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);  // Create if not exist, truncate if exist; 644 permissions to allow read/write for owner and read for group/others
    if (dest_fd == -1) {
        perror("Unable to open/create destination file");
        close(source_fd);
        exit(1);
    }

    // Part 2: Copying the file
    char buffer[1024];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0) {    // Check if read is successful and complete
        bytes_written = write(dest_fd, buffer, bytes_read);    // Write the read bytes to the destination file
        if (bytes_written == -1) {
            perror("Unable to write to destination file");
            close(source_fd);
            close(dest_fd);
            exit(1);
        }
    }

    if (bytes_read == -1) perror("Error occurred during reading");  // Feedback for read error
    else printf("File copied successfully.\n");
    
    close(source_fd);
    close(dest_fd);

    return 0;
}