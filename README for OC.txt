DESIGNED and IMPLEMENTED by 
Harshit Vishwakarma
(ACM Technical Team Member)

populate the participant.txt file
in the format
1_<rollnumber>_<rating>\n

_ denotes space/blankspace, \n denotes Enter key.

Sample Data:
1 101917204 88
1 101908114 92
1 101903191 95
1 101903121 65
1 101903054 56
1 101917207 90
1 101917187 89
1 101917056 75
1 101903044 54
1 101903077 52
1 101917200 67

NOTICE THAT THERE IS \n at the last record too.

Open Matches.txt for the optimum matches for a given participants in participants.txt
Open results.txt for the Final result after we have finalized the declaration of result.

How To Operate matchGenACM.exe
-----------------------
Make Sure that these files are in same folder,
matchGenACM.exe, matchGenACM.cpp, matches.txt, participants.txt, README for OC.txt, results.txt

open CMD and Navigate to the folder which conatins these files,
run match.exe

the program automatically picks the participants from participants.txt
and ask if you want to generate Match, press y for yes, n for no.

after a Yes, the optimum matches a displayed on your screen and is saved in matches.txt file.

after any match ends, we declare the winner for each match.
select the Match number by entering match number.
then select which side won, L for left and R for right.

after all the matches have been concluded 
enter -1.
press y for finalization of results, n for returning back to declaration of match.

After finalization the participants starting with 1 are going to continue the event,
and those starting from 0 are knocked-out.
The results are saved in results.txt file.

Re-populate the participant.txt file for next round.