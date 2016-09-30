from twython import Twython

C_K = "Your_consumer_key"
C_S = "Your_consumer_key"
A_K = "Your_consumer_key"
A_S = "Your_consumer_key"


api = Twython (C_K, C_S, A_K, A_S)

api.update_status(status="Hello World")
