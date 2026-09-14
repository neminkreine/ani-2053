C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu>powershell -Command "Measure-Command { jenga build --project MonEssai --config Debug }"


Days              : 0
Hours             : 0
Minutes           : 0
Seconds           : 5
Milliseconds      : 624
Ticks             : 56243252
TotalDays         : 6.50963564814815E-05
TotalHours        : 0.00156231255555556
TotalMinutes      : 0.0937387533333333
TotalSeconds      : 5.6243252
TotalMilliseconds : 5624.3252




C:\Users\ASUS\OneDrive\Desktop\code\Nkentseu>powershell -Command "Measure-Command { jenga build --project MonEssai --config Release }"


Days              : 0
Hours             : 0
Minutes           : 1
Seconds           : 4
Milliseconds      : 522
Ticks             : 645229896
TotalDays         : 0.000746793861111111
TotalHours        : 0.0179230526666667
TotalMinutes      : 1.07538316
TotalSeconds      : 64.5229896
TotalMilliseconds : 64522.9896

Le tempps de construction Debug est sensiblement de 5secondes et 6 Milliseconds tandis que le temps de construction Release est de sensiblement 1minute et 4 secondes

les lignes de MonEssai.jenga, que j'ai reussi a exploiter grace a une IA, qui expliquent ces nombres sont:
with filter("config: Debug"):
        defines(["_DEBUG"])
        optimize("Off")
        symbols(True)

    with filter("config: Release"):
        defines(["NDEBUG"])
        optimize("Speed")
        symbols(False)