/**
 * An example ldns program
 *
 * Setup a resolver
 * Query a nameserver
 * Print the result
 */

#include <config.h>
#include <ldns/resolver.h>
        
int
main(void)
{       
        ldns_resolver *res;
        ldns_rdf *qname;
        ldns_rdf *nameserver;
	ldns_rdf *defdomain;
        ldns_pkt *pkt;
        char *server_ip;
        char *name;
        char *type;
        
        /* init */
        res = ldns_resolver_new(); 
        if (!res)
                return -1;

        nameserver  = ldns_rdf_new_frm_str("127.0.0.1", LDNS_RDF_TYPE_A);
        if (ldns_resolver_push_nameserver(res, nameserver) != LDNS_STATUS_OK) {
		printf("error push nameserver\n");
		return -1;
	}
	/* HACK */
	ldns_resolver_set_configured(res, 1);

        qname = ldns_dname_new_frm_str("www.miek.nl.");
        pkt = ldns_resolver_send(res, qname, LDNS_RR_TYPE_A, 0, LDNS_RD);
        pkt = ldns_resolver_send(res, qname, LDNS_RR_TYPE_A, 0, LDNS_RD);
        return 0;
}
