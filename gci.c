#include <httpd.h>
#include <http_protocol.h>
#include <http_config.h>

static int gci_handler(request_rec* r)
{
    if (!r->handler || strcmp(r->handler, "gci"))
        return DECLINED;

    if (r->method_number != M_GET)
        return HTTP_METHOD_NOT_ALLOWED;

    ap_set_content_type(r, "text/html");
    ap_rprintf(r, 
		"<div style='background-color:#1A2C2E;height:100%;width:100%;display:flex;align-items: center;justify-content: center;'><img style='padding-bottom:100px;' src='https://codein.withgoogle.com/static/img/og-image.png' /><h1 style='color:#00CAEA;font-size:130px;text-align:center;padding-bottom:100px;margin-left:20px;' >WELCOME TO GCI 2019</h1></div>");
    return OK;
}

static void register_hooks(apr_pool_t* pool)
{
    ap_hook_handler(gci_handler, NULL, NULL, APR_HOOK_MIDDLE);
}

module AP_MODULE_DECLARE_DATA gci_module = {
    STANDARD20_MODULE_STUFF,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    register_hooks
};
