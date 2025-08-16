LAYOUT ?= hello
WVKBD_DIR = vendor/wvkbd
LAYOUT_DIR = layout
HEADERS = $(shell find "${LAYOUT_DIR}" -name "*.h")

build : copy-layout wvkbd-build copy-bin clean-layout
.PHONY : build

copy-layout :
	@case "${LAYOUT}" in \
	mobintl|deskintl) \
		;; \
	*) \
		cp -p "${LAYOUT_DIR}/${LAYOUT}/layout.h" "${WVKBD_DIR}/layout.${LAYOUT}.h"; \
		cp -p "${LAYOUT_DIR}/${LAYOUT}/keymap.h" "${WVKBD_DIR}/keymap.${LAYOUT}.h"; \
		cp -p "${LAYOUT_DIR}/${LAYOUT}/config.h" "${WVKBD_DIR}/config.${LAYOUT}.h"; \
		;; \
	esac
.PHONY : copy-layout

wvkbd-build :
	make -C "${WVKBD_DIR}" LAYOUT="${LAYOUT}"
.PHONY : wvkbd-build

copy-bin :
	mv "${WVKBD_DIR}/wvkbd-${LAYOUT}" .
.PHONY : copy-bin

clean : wvkbd-clean clean-layout
.PHONY : clean

wvkbd-clean :
	make -C "${WVKBD_DIR}" clean LAYOUT="${LAYOUT}"
.PHONY : wvkbd-clean

clean-layout :
	@case "${LAYOUT}" in \
	mobintl|deskintl) \
		;; \
	*) \
		rm -f "${WVKBD_DIR}/layout.${LAYOUT}.h"; \
		rm -f "${WVKBD_DIR}/keymap.${LAYOUT}.h"; \
		rm -f "${WVKBD_DIR}/config.${LAYOUT}.h"; \
		;; \
	esac
.PHONY : clean-layout

format:
	clang-format -i ${HEADERS}

check-format:
	clang-format --dry-run --Werror ${HEADERS}
