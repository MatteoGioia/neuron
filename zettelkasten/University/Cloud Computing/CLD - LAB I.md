1. We run the docker container in detached mode to ensure it works in the background, without being tied to the console (e.g. STDIN/STDOUT are not redirected on the shell promtp). This could be useful for many reasons, such as invoking other commands in the terminal.

2. A container is a sandboxed process. This is achieved through the use of namespaces (showing the container only certain "parts" of the system) and c-groups (only allowing for certain capabilities). A container does have everything needed to run and it includes an isolated filesystem. Each container is based on a container image, which basically contains all it's needed for the container to run, including the filesystem itself and configuration settings. An image can be also seen as a snapshot of the container itself, as one can create images of running container to "export" them later on.

3. Commands:

    3a. FROM node:12-alpine // Build the container using the node:12-alpine image as a base. 
    
    3b. RUN apk add --no-cache python2 g++ make // runs a shell command (apk is the default package manager for alpine) that installs all tools necessary to build the app, uses the result as input for the next step
    
    3c. WORKDIR /app // change the default working directory to /app for any command that follows
    
    3d. COPY . . // copies the content of the current folder 

    3e. RUN yarn install --production // installs the needed dependencies
    
    3f. CMD ["node", "src/index.js"] // default code to be ran everytime the container is executed

4. We tag image to make identyfing containers simpler. Normally a container can be identified by the name, chosen with the tag or randomly assigned, or the ID.

5. Port mapping is necessary to use our application, as it exposes a webpage on the port nr.3000 internal to the container. We just tell the container to map its 3000th port to the host 3000th port.

6. No, only 1 process can listen to a specific port. For instance, if we have 2 processes that expose a webpage on the 8080 port, one will have to switch to a different port.

7. One might need to remove a container to push a big code update to a deployed app, or simply to free up space used by old containers. One solution can also be to use ephemeral containers, which auto delete when stopped, using the --rm flag.

8. Ideally a container must be stopped before we are able to remove it. Not stopping could lead to error, as graceful stop allows the docker daemon to send a SIG_HUP signal to the container which has time to clean up the running taks.