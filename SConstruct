# -*- mode: python -*-

env=Environment()

env.ParseConfig("pkg-config --cflags --libs glib-2.0")
env.Append(CFLAGS=Split("-g -ggdb -Wall"))
env.Append(CPPPATH=Split("#/include"))
env.Append(LIBPATH=Split("#/lib"))

Export("env")

PROFILES=Split("debug release")
profile=ARGUMENTS.get("profile", "release")
if profile not in PROFILES:
    print "Unknown profile '%s', known profiles: %s" % (profile, str(PROFILES))

SUBDIRS=Split("src")
for e in SUBDIRS:
    env.SConscript("%s/SConscript" % e)
