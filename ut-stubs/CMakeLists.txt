add_library(ut_psp-${CFE_PSP_TARGETNAME}_stubs
    cfe_psp_stubs.c
    cfe_psp_handlers.c
    cfe_psp_global_stubs.c
)
target_link_libraries(ut_psp-${CFE_PSP_TARGETNAME}_stubs PRIVATE
    psp_module_api
    ut_assert
)
