using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NSGA2Sharp
{
    public partial class NSGA2
    {
        /* Insert an element X into the list at location specified by NODE */
        void insert(ref lists node, int x)
        {
            if (node == null)
            {
                throw new Exception("\n Error!! asked to enter after a invalid node, hence exiting");
            }
            lists temp = new lists();
            temp.index = x;
            temp.parent = node;
            temp.child = node.child;
            if (node.child != null) // a valid child
            {
                node.child.parent = temp;
            }
            node.child = temp;
            return;
        }

        /* Delete the node NODE from the list */
        lists del(ref lists node)
        {
            lists temp;
            if (node == null)
            {
                throw new Exception("\n Error!! asked to delete a NULL pointer, hence exiting \n");
            }
            temp = node.parent;
            temp.child = node.child;
            if (temp.child != null)
            {
                temp.child.parent = temp;
            }
            return (temp);
        }
    }
}
