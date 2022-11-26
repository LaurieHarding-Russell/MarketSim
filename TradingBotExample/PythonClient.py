# Python Client For MarketSim

import requests

HOST = "127.0.0.1" # change

INVESTOR_ENDPOINT = "/investor"

def register(registerData: RegisterData):
    return requests.post(HOST + INVESTOR_ENDPOINT + "/register", data=registerData)


class RegisterData(object):
    name: name
    def __init__(self, name, host, port):
        self.name = name
