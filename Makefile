LAYOUT ?= hello
WVKBD_DIR = vendor/wvkbd
LAYOUT_DIR = layout
HEADERS = $(shell find "${LAYOUT_DIR}" -name "*.h")

build :
	@case "${LAYOUT}" in \
	mobintl|deskintl) \
		;; \
	*) \
		cp -p "${LAYOUT_DIR}/${LAYOUT}/layout.h" "${WVKBD_DIR}/layout.${LAYOUT}.h"; \
		cp -p "${LAYOUT_DIR}/${LAYOUT}/keymap.h" "${WVKBD_DIR}/keymap.${LAYOUT}.h"; \
		cp -p "${LAYOUT_DIR}/${LAYOUT}/config.h" "${WVKBD_DIR}/config.${LAYOUT}.h"; \
		;; \
	esac
	make -C "${WVKBD_DIR}" LAYOUT="${LAYOUT}"
	mv "${WVKBD_DIR}/wvkbd-${LAYOUT}" .
.PHONY : build

clean :
	make -C "${WVKBD_DIR}" "${@}" LAYOUT="${LAYOUT}"
	@case "${LAYOUT}" in \
	mobintl|deskintl) \
		;; \
	*) \
		rm -f "${WVKBD_DIR}/layout.${LAYOUT}.h"; \
		rm -f "${WVKBD_DIR}/keymap.${LAYOUT}.h"; \
		rm -f "${WVKBD_DIR}/config.${LAYOUT}.h"; \
		;; \
	esac
.PHONY : clean

format:
	clang-format -i ${HEADERS}

check-format:
	clang-format --dry-run --Werror ${HEADERS}
