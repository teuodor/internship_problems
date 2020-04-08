import ast


#clasa pentru o ora din intervalul orar
class Time:
    def __init__(self, hour, minute):
        self.hour = hour
        self.minute = minute

    def __sub__(self, other):
        return Time("0", (int(self.hour) - int(other.hour)) * 60 + (int(self.minute) - int(other.minute)))

    def __ge__(self, other):
        return (int(self.hour) * 60 + int(self.minute)) >= (int(other.hour) * 60 + int(other.minute))

    def __gt__(self, other):
        return (int(self.hour) * 60 + int(self.minute)) > (int(other.hour) * 60 + int(other.minute))

    def __lt__(self, other):
        return (int(self.hour) * 60 + int(self.minute)) < (int(other.hour) * 60 + int(other.minute))

    def __ne__(self, other):
        return self.hour != other.hour or self.minute != other.minute

    def __eq__(self, other):
        return self.hour == other.hour and self.minute == other.minute

    def __str__(self):
        return self.hour + ":" + self.minute


#clasa pentru intervalul orar
class TimeFrame:
    def __init__(self, startTime, endTime):
        self.startTime = startTime
        self.endTime = endTime

    def __lt__(self, other):
        return self.endTime < other.startTime

    def __gt__(self, other):
        return self.startTime > other.endTime

    def __eq__(self, other):
        return self.startTime < other.endTime and self.endTime > other.startTime

    def __str__(self):
        return str(self.startTime) + " - " + str(self.endTime)


#returneaza un tuplu cu ora si minutele unui string de forma hh:mm
def hour_and_minute(string):
    return string.split(':')[0], string.split(':')[1]


def fill_meeting_calendar(calendar, limits_calendar, meeting_calendar):
    if calendar[0][0] != limits_calendar[0]:
        hour_min_lim = hour_and_minute(limits_calendar[0])
        hour_min_cal = hour_and_minute(calendar[0][0])
        meeting_calendar.append(
            TimeFrame(Time(hour_min_lim[0],hour_min_lim[1]),
                      Time(hour_min_cal[0], hour_min_cal[1])))

    for i in range(1, len(calendar)):
        hour_min1 = hour_and_minute(calendar[i - 1][1])
        hour_min2 = hour_and_minute(calendar[i][0])
        time1 = Time(hour_min1[0], hour_min1[1])
        time2 = Time(hour_min2[0], hour_min2[1])

        if time1 != time2:
            meeting_calendar.append(TimeFrame(time1, time2))

    if calendar[len(calendar) - 1][1] != limits_calendar[1]:
        hour_min_lim = hour_and_minute(limits_calendar[1])
        hour_min_cal = hour_and_minute(calendar[len(calendar) - 1][1])
        meeting_calendar.append(
            TimeFrame(Time(hour_min_cal[0], hour_min_cal[1]),
                      Time(hour_min_lim[0], hour_min_lim[1]))
        )


def meeting_time_frame(timeFrame1, timeFrame2, minimumTime):
    if timeFrame1.startTime < timeFrame2.startTime and (timeFrame1.endTime < timeFrame2.endTime or timeFrame1.endTime == timeFrame2.endTime):
        if (timeFrame1.endTime - timeFrame2.startTime) >= minimumTime:
            return TimeFrame(timeFrame2.startTime, timeFrame1.endTime)
    elif (timeFrame1.startTime < timeFrame2.startTime or timeFrame1.startTime == timeFrame2.startTime) and timeFrame1.endTime > timeFrame2.endTime:
        if (timeFrame2.endTime - timeFrame2.startTime) >= minimumTime:
            return timeFrame2
    elif timeFrame1.startTime > timeFrame2.startTime and (timeFrame1.endTime > timeFrame2.endTime or timeFrame1.endTime == timeFrame2.endTime):
        if (timeFrame2.endTime - timeFrame1.startTime) >= minimumTime:
            return TimeFrame(timeFrame1.startTime, timeFrame2.endTime)
    elif (timeFrame1.startTime > timeFrame2.startTime or timeFrame1.startTime == timeFrame2.startTime) and timeFrame1.endTime < timeFrame2.endTime:
        if (timeFrame1.endTime - timeFrame1.startTime) >= minimumTime:
            return timeFrame1

    return None


def run():
    f = open("input.in", "r")
    string = f.readline()
    calendar1 = ast.literal_eval(string)

    string = f.readline()
    limits_calendar1 = ast.literal_eval(string)

    string = f.readline()
    calendar2 = ast.literal_eval(string)

    string = f.readline()
    limits_calendar2 = ast.literal_eval(string)

    string = f.readline()
    minimum_time = Time("0", string)

    meeting_calendar1 = []
    meeting_calendar2 = []
    meeting_calendar = []

    #facem 2 liste cu perioade de timp in care cei 2 sunt liberi
    fill_meeting_calendar(calendar1, limits_calendar1, meeting_calendar1)
    fill_meeting_calendar(calendar2, limits_calendar2, meeting_calendar2)

    it_calendar1 = 0
    it_calendar2 = 0

    #se foloseste "or" deoarece ar trebui sa iteram in celalta lista chiar daca am ajuns la finalul unei liste
    while it_calendar1 != len(meeting_calendar1) or it_calendar2 != len(meeting_calendar2):
        #acest if ne spune daca am ajuns totusi cu o lista mai departe decat are ea capacitatea
        if it_calendar1 == len(meeting_calendar1) or it_calendar2 == len(meeting_calendar2):
            break

        #primele doua conditii sunt cazurile in care cele doua intervale nu se suprapun
        if meeting_calendar1[it_calendar1] < meeting_calendar2[it_calendar2]:
            it_calendar1 += 1
        elif meeting_calendar1[it_calendar1] > meeting_calendar2[it_calendar2]:
            it_calendar2 += 1
        else:
            time_frame_1 = meeting_calendar1[it_calendar1]
            time_frame_2 = meeting_calendar2[it_calendar2]
            meeting_time = meeting_time_frame(time_frame_1, time_frame_2, minimum_time)

            #meeting_time este None daca intervalul de timp in care s-ar putea intalni este mai mic decat perioada minima
            if meeting_time is not None:
                meeting_calendar.append(meeting_time)

            #iteram in liste in functie de ora de incheiere al unui interval
            if time_frame_1.endTime < time_frame_2.endTime:
                it_calendar1 += 1
            elif time_frame_1.endTime > time_frame_2.endTime:
                it_calendar2 += 1
            else:
                it_calendar1 += 1
                it_calendar2 += 1

    print([str(time) for time in meeting_calendar])


run()
