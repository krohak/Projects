from twython import TwythonStreamer

C_K = "Your_consumer_key"
C_S = "Your_consumer_key"
A_K = "Your_consumer_key"
A_S = "Your_consumer_key"

class MyStreamer(TwythonStreamer):
	def on_success(self,data):
		if 'text' in data:
			print("Found it")
			print data['text']


stream = MyStreamer (C_K, C_S, A_K, A_S)

stream.statuses.filter(track="raspberry pi")
