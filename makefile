# Определяем подкаталоги
SUBDIRS = libmysyslog libmysyslog-json libmysyslog-text libmysyslog-client libmysyslog-daemon

# Цель по умолчанию
all: $(SUBDIRS)

# Правило для запуска make в подкаталогах
$(SUBDIRS):
	$(MAKE) -C $@

# Цель clean для очистки всех подкаталогов
clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

run-client:
	$(MAKE) -C libmysyslog-client run

run-daemon:
	$(MAKE) -C libmysyslog-daemon run

.PHONY: all clean $(SUBDIRS)
