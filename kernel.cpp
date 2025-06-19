extern "C" void kernelMain() {
    char* video = (char*)0xb8000;

    for (int i = 0; i < 80 * 25 * 2; i += 2) {
        video[i] = ' ';      
        video[i + 1] = 0x07;  
    }

    const char* message = "Hello from my new OS!";
    for (int i = 0; message[i] != '\0'; ++i) {
        video[i * 2] = message[i];    
        video[i * 2 + 1] = 0x0F;       
    }
}
