# cmdtimeout #
a command line starter, which kills the child process after a timeout if it has not finished.

## Usage ##
`cmdtimeout time command [argumentlist]`

* time: [00h][00m][00[s]] 
    After the time has elapsed, the process is killed. The hour and minute section is optional. It is valid to only set the minutes or the seconds. A umber without a unit is interpreted as seconds.
* command: command which will run as child process.
* argumentlist: arguments, which are passed to the child process without changes.
 


