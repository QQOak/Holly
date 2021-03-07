# Environment

## Python Virtualenv
### Install virtualenv
$ sudo python3 -m pip install virtualenv

### Install virtualenvwrapper
```bash
$ sudo python3 -m pip install virtualenvwrapper
```

Then find the path currently in use...
```bash
$ which virtualenvwrapper.sh
$ /usr/local/bin/virtualenvwrapper.sh
```

... and then add it to your profile
```bash
$ nano.profile

and add
```bash
source /usr/local/bin/virtualenvwrapper.sh
```
to the bottom.
Log out and back in for the changes to take effect.


## MMQT
### Install Broker
```bash
$ sudo apt install mosquitto
```

### ...and run as Daemon
```bash
$ mosquitto -d
```

### Install Client (only on machines you want to test from )
```bash
$ sudo apt install mosquitto-clients
```

### Get client to subscribe to a topic
```bash
$ mosquitto_sub -d -t testTopic
$ mosquitto_sub -d -h <ipaddress> -t testTopic
```


### publish a message
```bash
$ mosquitto_pub -d -t testTopic -m "Hello World!"
$ mosquitto_pub -d -h <ipaddress> -t testTopic -m "Hello World!"
```