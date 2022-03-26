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

8. (Ideally) A container must be stopped before we are able to remove it. Not stopping could lead to error, as graceful stop allows the docker daemon to send a SIG_HUP signal to the container which has time to clean up the running taks.

9. It depends. Most of the images will run on any docker host without issues assuming no port is already occupied (or any similar simple issue is present), however, depending on the architecture the image was built for, there might be compatibility problems. For instance, old jupyter-notebook container images don't run nicely (and in some cases they do not run at all) on M1 macs (arm64), as they expect the underlying arch to be x86 intel/amd.

10. No, although the image used for both containers is the same, they do not share the same filesystem. This is possible through the use of namespaces.

11. The -d option allows for container to run in the background, however it expects the container to run some command in foreground of its shell or it will actually stop it. This is because the host believes the container has actually stopped doing anything. Outputting some value and redirecting it to dev/null (= trashing it) keeps the container running.

12. The docker exec command allows to interact with a container by running a new command inside it. It requires the ID of the running container and a command to run (i.e. "bash"). 

13. When mounting the volume to "etc/todos", we make sure that some folder in the container is mapped to a persistent folder inside the docker host (and we call this folder a volume). However, we do not actually "modify" the filesystem of the container itself, but rather the namespace of the container is modified so that now "it sees" the volume and its "etc/todos" folder actually points at that folder. So when writing on etc/todos, the container actually writes on the volume.

14. My volume is located at "/var/lib/docker/volumes/todo-db/_data" (being on linux). 

15. A dev mode container is a container configured in such a way that it supports a developement workflow (e.g. it does not need to be restarted everytime a change to the source code is made). This is possible because the command used to run it can include the needed dependencies and services like nodemon can look for changes on the source code and automatically rebuild the app as they are applied. Furthermore, we are able to edit the source code live since the docker container is now bound to a folder in the filesystem chosen by us through mount-binding.

16. Yes, but we might eventually need to rebuild the container image if we want to be able to use it without having to reapply all the changes. 

17. A docker service is an entry defined in the docker compose file, together with all the necessary requirements to make it run, like port mapping or restart policies/allowed resource usage etc. Many services put together constitute what's called a "stack". Services are also defined in the context of docker swarm as tasks to be executed by the master or worker nodes, as it's a special mode that the docker host can use to be able to manage clusters of docker engines.

18. NEED CLARIFICATION

19. Yes, we can, provided that we declare such volume in the volume section if we are using docker-compose.

20. Yes but only if we have services that depend on each other. In that case it would be appropriate to use the "depends_on" flag (or others) to instruct docker to start the service only after the ones needed for it to work.

21. No, a default one will be used when creating the stack. However, it might still be a good idea to define a network if our application is complex or we want to test a real world scenario.

22. Theorically yes, we can obtain kind of the same result with the command line. However, docker-compose makes it much easier by only having to invoke one command, creating a network for us, making the syntax more readable and so on. Furthermore, it makes the removal of the network and volumes (if --volumes tag is used) automatic, whereas we would have to add specific tags in the docker run command to ensure that happens. Finally, the docker compose makes it easier to abstract and write more complex configurations, are the yml language is easier to read than one gigantic command line.