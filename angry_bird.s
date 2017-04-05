.name "Angry bird"
.comment "flying just a little bit"

clean:
	st r1, 26
	st r1, 30
	st r10, :clean
	st r10, -12
	st r10, -14

alive:
	live %999
	fork %:alive
	live %999
