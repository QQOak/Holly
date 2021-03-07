# Environment

## Python Virtualenv
### Install virtualenv
sudo python3 -m pip install virtualenv

### Install virtualenvwrapper

## MMQT
### Install Broker
```bash
sudo apt install mosquitto
```

### ...and run as Daemon
```bash
mosquitto -d
```

### Install Client (only on machines you want to test from )
```bash
sudo apt install mosquitto-clients
```

### Get client to subscribe to a topic
```bash
mosquitto_sub -d -t testTopic
mosquitto_sub -d -h <ipaddress> -t testTopic
```


### publish a message
```bash
mosquitto_pub -d -t testTopic -m "Hello World!"
mosquitto_pub -d -h <ipaddress> -t testTopic -m "Hello World!"
```