TEMPLATE = subdirs

SUBDIRS += \
    core \
    CardManagerQml

CardManagerQml.subdir = CardManagerQml
core.subdir = core

CardManagerQml.depends = core
