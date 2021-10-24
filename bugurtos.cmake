cmake_minimum_required(VERSION 3.13)

if (NOT TARGET _bugurtos_inclusion_guard)
	add_library(_bugurtos_inclusion_guard INTERFACE)

    message(NOTICE "BuguRTOS: Configuring build..")

    if (NOT BGRT_CONFIG_DIR)
		message(FATAL_ERROR "BuguRTOS: BGRT_CONFIG_DIR must be specified")
	endif()
    get_filename_component(BGRT_CONFIG_DIR "${BGRT_CONFIG_DIR}" REALPATH)

	if (NOT BGRT_ARCH)
		message(FATAL_ERROR "BuguRTOS: BGRT_ARCH must be specified")
	endif()

    if (NOT BGRT_TOOLCHAIN)
        message(NOTICE "BuguRTOS: BGRT_TOOLCHAIN was not set, will default to \"gcc\"...")
        set(BGRT_TOOLCHAIN "gcc")
	endif()

    #Get current dir path
    set(BGRT_DIR "${CMAKE_CURRENT_LIST_DIR}")
	get_filename_component(BGRT_DIR "${BGRT_DIR}" REALPATH)

    ###########################################################################
    #                         Kernel source files
    ###########################################################################
    set(BGRT_DEFAULT_SYSCALL_TABLE_DIR "${BGRT_DIR}/kernel/default")

    if (NOT BGRT_SYSCALL_TABLE_DIR)
        message(NOTICE "BuguRTOS: BGRT_SYSCALL_TABLE_DIR was not set, will default to \"${BGRT_DEFAULT_SYSCALL_TABLE_DIR}\"...")
        set(BGRT_SYSCALL_TABLE_DIR ${BGRT_DEFAULT_SYSCALL_TABLE_DIR})
    endif()
    get_filename_component(BGRT_SYSCALL_TABLE_DIR "${BGRT_SYSCALL_TABLE_DIR}" REALPATH)

    #Kernel files
    set(BGRT_KERNEL_SOURCES
            "${BGRT_DIR}/kernel/crit_sec.c"
            "${BGRT_DIR}/kernel/index.c"
			"${BGRT_DIR}/kernel/item.c"
			"${BGRT_DIR}/kernel/kernel.c"
			"${BGRT_DIR}/kernel/pcounter.c"
			"${BGRT_DIR}/kernel/pitem.c"
			"${BGRT_DIR}/kernel/proc.c"
			"${BGRT_DIR}/kernel/sched.c"
			"${BGRT_DIR}/kernel/sync.c"
			"${BGRT_DIR}/kernel/syscall.c"
			"${BGRT_DIR}/kernel/timer.c"
			"${BGRT_DIR}/kernel/vint.c"
			"${BGRT_DIR}/kernel/xlist.c"
            )

    #--------------------------------------------------------------------------
    #Port files
    #--------------------------------------------------------------------------
    set(BGRT_PORT_DIR "${BGRT_DIR}/arch/${BGRT_ARCH}/${BGRT_TOOLCHAIN}")
    
    #Add bugurt_port.c
    list(APPEND BGRT_KERNEL_SOURCES ${BGRT_PORT_DIR}/bugurt_port.c)

    #Add bugurt_proc_stack_init.c if needed!
    set(BGRT_STACK_INIT_C ${BGRT_PORT_DIR}/bugurt_proc_stack_init.c)
    message(NOTICE "BuguRTOS: Check for \"${BGRT_STACK_INIT_C}\"...")
    if (EXISTS ${BGRT_STACK_INIT_C})
        list(APPEND BGRT_KERNEL_SOURCES ${BGRT_STACK_INIT_C})
    endif()

    #Add bugurt_port_asm.S if needed!
    set(BGRT_PORT_ASM_S ${BGRT_PORT_DIR}/bugurt_port_asm.S)
    message(NOTICE "BuguRTOS: Check for \"${BGRT_PORT_ASM_S}\"...")
    if (EXISTS ${BGRT_PORT_ASM_S})
        list(APPEND BGRT_KERNEL_SOURCES ${BGRT_PORT_ASM_S})
    endif()
    
    ###########################################################################
    #                          Kernel include dirs
    ###########################################################################
    set(BGRT_KERNEL_INCLUDES
			${BGRT_DIR}/kernel
			${BGRT_SYSCALL_TABLE_DIR}
            ${BGRT_PORT_DIR}
            ${BGRT_CONFIG_DIR}
            )

    ###########################################################################
    #                             Kernel library
    ###########################################################################
    add_library(bugurtos_kernel INTERFACE)
	target_sources(bugurtos_kernel INTERFACE ${BGRT_KERNEL_SOURCES})
	target_include_directories(bugurtos_kernel INTERFACE ${BGRT_KERNEL_INCLUDES})

    ###########################################################################
    #                           Native API library
    ###########################################################################
    if (BGRT_SYSCALL_TABLE_DIR STREQUAL ${BGRT_DEFAULT_SYSCALL_TABLE_DIR})
        message(NOTICE "BuguRTOS: Adding native API...")
        add_library(bugurtos_native_api INTERFACE)
        target_sources(bugurtos_native_api INTERFACE 
                "${BGRT_DIR}/libs/native/cond.c"
                "${BGRT_DIR}/libs/native/ipc.c"
                "${BGRT_DIR}/libs/native/mutex.c"
                "${BGRT_DIR}/libs/native/sem.c"
                )
        target_include_directories(bugurtos_native_api INTERFACE 
                ${BGRT_KERNEL_INCLUDES}
                ${BGRT_DIR}/libs/native
                )
        message(NOTICE "BuguRTOS: Done!")
    endif()
endif()
