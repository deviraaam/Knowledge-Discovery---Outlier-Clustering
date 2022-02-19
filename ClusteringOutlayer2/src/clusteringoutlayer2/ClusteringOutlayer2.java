/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package clusteringoutlayer2;
import ALI.*;
import java.util.Map;

/**
 *
 * @author user
 */
public class ClusteringOutlayer2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        VectorLib vlib = new VectorLib();
        ClusteringLib cluslib = new ClusteringLib();
        double[][] data = {{80, 60, 75, 73, 81, 66}, {70, 84, 88, 90, 65, 60},
    {60, 40, 55, 58, 47, 49},{60, 65, 60, 70, 68, 72},{60, 35,40, 20, 56, 57}, 
    {95, 98, 85, 87, 93,95},{55, 70, 53, 64, 74, 77},{50, 53, 57, 63, 58, 40},{62, 64, 53, 58, 40, 45}};
        int k=2;
        int[] cluster=cluslib.Clustering("centroid", data, k);
        double[][] centroid=cluslib.getCentroid(data, cluster);
        
        int[] outlier=vlib.initArray(data.length, 0);
        double[] Davg=vlib.initArray(k, 0.0);
        int[] n_cluster=vlib.initArray(k, 0);
        double[] Dmin=new double[k];
        double alpha=1.8;
        
        double[] dist_to_centroid=new double[data.length];
        for (int i=0; i<cluster.length; i++) {
        dist_to_centroid[i]=vlib.getDistance(data[i], centroid[cluster[i]]);
        Davg[cluster[i]]=Davg[cluster[i]] + dist_to_centroid[i];
        n_cluster[cluster[i]] = n_cluster[cluster[i]] + 1;
        }
        
        for (int i=0; i<k; i++) {
        Davg[i]= Davg[i] / n_cluster[i];
        Dmin[i]=Davg[i] * alpha;
        }
        for (int i=0; i<cluster.length; i++)
        if (dist_to_centroid[i]>Dmin[cluster[i]])
        outlier[i]=1;
        
        vlib.view(outlier);
        /*
        VectorLib vlib = new VectorLib();
        ClusteringLib cluslib = new ClusteringLib();
        double[][] data = {{20,10}, {22,40}, {18,50}, 
    {17,52},{21,55},{30,45}, {25,53},{17,75},
    {80,40},{85,80},{87,85},{77,86},{78,88},{77,97}};
        int k=2;
        int[] cluster=cluslib.Clustering("centroid", data, k);
        double[][] centroid=cluslib.getCentroid(data, cluster);
        
        int[] outlier=vlib.initArray(data.length, 0);
        double[] Davg=vlib.initArray(k, 0.0);
        int[] n_cluster=vlib.initArray(k, 0);
        double[] Dmin=new double[k];
        double alpha=1.5;
        
        double[] dist_to_centroid=new double[data.length];
        for (int i=0; i<cluster.length; i++) {
        dist_to_centroid[i]=vlib.getDistance(data[i], centroid[cluster[i]]);
        Davg[cluster[i]]=Davg[cluster[i]] + dist_to_centroid[i];
        n_cluster[cluster[i]] = n_cluster[cluster[i]] + 1;
        }
        
        for (int i=0; i<k; i++) {
        Davg[i]= Davg[i] / n_cluster[i];
        Dmin[i]=Davg[i] * alpha;
        }
        for (int i=0; i<cluster.length; i++)
        if (dist_to_centroid[i]>Dmin[cluster[i]])
        outlier[i]=1;
        
        vlib.view(outlier);
*/
    }
    
}
