function playtone(freq,sf,amplitude,duration)
t=[0:1/sf:duration];
sound_vector=amplitude*sin(2*pi*freq*t);
soundsc(sound_vector,sf);